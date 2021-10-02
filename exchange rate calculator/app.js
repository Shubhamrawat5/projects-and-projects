const rate = document.querySelector('small');
const swap = document.querySelector('.btn');
const curOne = document.querySelector('#currency-one');
const curTwo = document.querySelector('#currency-two');
const curOneVal = document.querySelector('.cur-one-val');
const curTwoVal = document.querySelector('.cur-two-val');

calculate();

function swapCurrencies(e) {
  [curOne.value, curTwo.value] = [curTwo.value, curOne.value];
  calculate();

  e.preventDefault();
}  

function calculate() {
  fetch(`https://v6.exchangerate-api.com/v6/04a16a5442c2c589806dac1b/pair/${curOne.value}/${curTwo.value}`)
    .then(res => res.json())
    .then(data => {
      const exchange = data.conversion_rate;

      curTwoVal.value = exchange;
      rate.textContent = `1 ${curOne.value} = ${exchange} ${curTwo.value}`;
    });

}  

// Event Listeners
swap.addEventListener('click', swapCurrencies);
curOneVal.addEventListener('input', calculate);
curOne.addEventListener('change', calculate);
curTwo.addEventListener('change', calculate);