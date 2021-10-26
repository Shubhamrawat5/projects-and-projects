const searchName = document.querySelector('#search-name');
const searchLat = document.querySelector('#search-lat');
const searchLong = document.querySelector('#search-long');
const suggestions = document.querySelector('#suggestions');
const searchForm = document.querySelector('#search-name-form');
const searchLatLongForm = document.querySelector('#search-latlong-form')
const weatherCardContainer = document.querySelector('#weather-card-container');

async function getForecast(q){
    return axios.get('/api/forecast',{
        params: {
            q
        }
    })
}

async function getSearch(q){
    return axios.get('/api/search',{
        params: {
            q
        }
    })
}

searchName.addEventListener('input',async function(){
    if(this.value==="") return;
    try{
        const response = await getSearch(this.value);
        suggestions.replaceChildren();
        for(const loc of response.data){
            const opt = document.createElement('option');
            opt.value = loc.name;
            suggestions.append(opt);
        }
    }catch{}
})

searchForm.addEventListener('submit',async function(e){
    e.preventDefault();
    if(!this.checkValidity()) return;
    try{
        const response = await getForecast(searchName.value);
        updateWeatherCard(response.data);
        updateTempGraphCard(response.data);
    }catch(err){
        console.log(err);
        addAlert(`Unable to look for ${searchName.value}`);
    }
})

searchLatLongForm.addEventListener('submit',async function(e){
    e.preventDefault();
    if(!this.checkValidity()) return;
    try{
        const response = await getForecast(`${searchLat.value},${searchLong.value}`);
        updateWeatherCard(response.data);
        updateTempGraphCard(response.data);
    }catch{
        addAlert('Unable to look for the given values');
    }
})

function updateWeatherCard(body){
    const div = document.createElement('div');
    const oldDiv = document.querySelector('#weather-card');
    if(oldDiv) oldDiv.remove();
    div.classList.add('col-12','col-sm-10','offset-sm-1','col-md-6','offset-md-3','col-xl-4','offset-xl-4','mb-2');
    div.id = 'weather-card';
    div.innerHTML = `
        <div class="card border-0" style="box-shadow: 0px 0px 7px 0px #0000005e;">
            <div class="card-body">
                <div class="d-flex justify-content-between mb-2">
                    <div>
                        <div class="h2">${body.location.name}, ${body.location.region}, ${body.location.country}</div>
                        <div class="h4 d-flex">
                            <div class="me-2"><sup>Lat</sup>${body.location.lat}</div>
                            <div><sup>Long</sup>${body.location.lon}</div>
                        </div>
                        <div class="h3">
                            ${body.location.localtime}
                        </div>
                    </div>
                    <div class="d-flex align-items-center">
                        <img src="${body.current.condition.icon}">
                        <span class="h4 mb-0">${body.current.condition.text}</span>
                    </div>
                </div>
                    <div class="d-flex justify-content-between">
                        <div class="h2 me-2">${body.current.temp_c}&deg;C | ${body.current.temp_f}&deg;F</div>
                        <div class="h2"><sup>Wind</sup> ${body.current.wind_kph}km/h <i class="bi bi-arrow-up" style="display: inline-block; transform: rotate(${body.current.wind_degree}deg)"></i></div>
                    </div>
                </div>
        </div>`;
    weatherCardContainer.append(div);
}

function updateTempGraphCard(body){
    const div = document.createElement('div');
    const oldDiv = document.querySelector('#temp-graph-card');
    if(oldDiv) oldDiv.remove();
    div.classList.add('col-12','col-sm-10','offset-sm-1','col-md-6','offset-md-3','col-xl-4','offset-xl-4','mb-2');
    div.id = 'temp-graph-card';
    div.innerHTML = `
        <div class="card border-0" style="box-shadow: 0px 0px 7px 0px #0000005e;">
            <div class="card-body d-flex flex-column align-items-center">
                <canvas id="temp-c-chart"></canvas>
                <canvas id="temp-f-chart" hidden></canvas>
                <div class="btn-group">
                    <input type="radio" class="btn-check" id="cBtn" name="tempUnit" checked>
                    <label class="btn btn-outline-primary" for="cBtn">&deg;C</label>
                    <input type="radio" class="btn-check" id="fBtn" name="tempUnit">
                    <label class="btn btn-outline-primary" for="fBtn">&deg;F</label>
                </div>
            </div>
        </div>`;
    const ctxC = div.querySelector('#temp-c-chart');
    const ctxF = div.querySelector('#temp-f-chart');
    const labels = [];
    const dataC = [];
    const dataF = [];
    for(let i=0;i<24;i++) labels.push(i);
    for(const hour of body.forecast.forecastday[0].hour){
        dataC.push(hour.temp_c);
        dataF.push(hour.temp_f);
    }
    const chartC = new Chart(ctxC,{
        type: 'line',
        data: {
            labels,
            datasets: [{
                data: dataC,
                backgroundColor: 'rgb(255,245,204)',
                borderColor: 'rgb(255,204,0)'
            }]
        },
        options: {
            aspectRatio: 3,
            legend: {
                display: false
            },
            scales: {
                xAxes: [{
                    gridLines: {
                        drawOnChartArea: false
                    },
                    scaleLabel: {
                        labelString: 'Time',
                        display: true
                    }
                }],
                yAxes: [{
                    gridLines: {
                        drawOnChartArea: false
                    },
                    scaleLabel: {
                        labelString: 'Temperature (°C)',
                        display: true
                    }
                }]
            }
        }
    });
    const chartF = new Chart(ctxF,{
        type: 'line',
        data: {
            labels,
            datasets: [{
                data: dataF,
                backgroundColor: 'rgb(255,245,204)',
                borderColor: 'rgb(255,204,0)'
            }]
        },
        options: {
            aspectRatio: 3,
            legend: {
                display: false
            },
            scales: {
                xAxes: [{
                    gridLines: {
                        drawOnChartArea: false
                    },
                    scaleLabel: {
                        labelString: 'Time',
                        display: true
                    }
                }],
                yAxes: [{
                    gridLines: {
                        drawOnChartArea: false
                    },
                    scaleLabel: {
                        labelString: 'Temperature (°F)',
                        display: true
                    }
                }]
            }
        }
    });
    const cBtn = div.querySelector('#cBtn');
    const fBtn = div.querySelector('#fBtn');
    function toggleGraph() {
        if(cBtn.checked){
            ctxC.hidden = false;
            ctxF.hidden = true;
        }else{
            ctxC.hidden = true;
            ctxF.hidden = false;
        }
    }
    cBtn.addEventListener('change',toggleGraph);
    fBtn.addEventListener('change',toggleGraph);
    weatherCardContainer.append(div);
}

function addAlert(message){
    const div = document.createElement('div');
    div.classList.add('col-12','col-sm-6','offset-sm-3','col-xl-4','offset-xl-4');
    div.innerHTML = `
        <div class="alert alert-danger alert-dismissible fade show d-flex justify-content-between pe-3">
            <div>${message}</div>
            <div class="spinner-border text-dark"></div>
        </div>`;
    const alertNode = div.querySelector('.alert');
    const alert = new bootstrap.Alert(alertNode);
    setTimeout(() => alert.close(), 2000);
    weatherCardContainer.prepend(div);
}