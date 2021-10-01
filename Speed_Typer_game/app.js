const settings = document.querySelector('#settings');
const navbar = document.querySelector('#navbar');
const uiTime = document.querySelector('.time');
const uiScore = document.querySelector('.score');
const selectList = document.querySelector('select');
const input = document.querySelector('input');
const startBtn = document.querySelector('#start');
const uiWord = document.querySelector('.word');
const card = document.querySelector('.card');
const rulesBtn = document.querySelector('#rules-btn');
const rulesContainer = document.querySelector('.container');
const closeBtn = document.querySelector('#close');

let timeInterval;
let timeLeft = 10;
let totalScore = 0;
let randomWord = '';

const words = [
  'sigh',
  'tense',
  'airplane',
  'ball',
  'pies',
  'juice',
  'warlike',
  'bad',
  'north',
  'dependent',
  'steer',
  'silver',
  'highfalutin',
  'superficial',
  'quince',
  'eight',
  'feeble',
  'admit',
  'drag',
  'loving'
];

function startGame(e) {
  if(e.target.textContent === 'Start Game') {
    timeLeft = 10;

    startBtn.textContent = 'Restart Game';
    startBtn.style.backgroundColor = '#d9534f';

    input.value = '';
  
    randomWord = getRandomWord();
  
    populateUI(randomWord, totalScore, timeLeft);
  
    timeInterval = setInterval(timeReduce, 1000);
  } else {
    window.location.reload();
  }
}

// Reduce time left
function timeReduce() {
  timeLeft--;
  if(timeLeft > 0) {
    populateUI(randomWord, totalScore, timeLeft);
  } else {
    clearInterval(timeInterval);
    changeState();
  }
}

// Update Difficulty
function updateDifficulty() {
  timeLeft = 10;
  totalScore = 0;
  randomWord = '';
  
  populateUI(randomWord, totalScore, timeLeft);
}

// Change State
function changeState() {
  card.innerHTML = `
    <h3>TIME RAN OUT</h3>
    <p class="display-score">Your final score is ${totalScore}</p>
    <button class="btn play-again">Play Again</button>
  `;
}

// Replay game
function replayGame(e) {
  if(e.target.classList.contains('play-again')) {
    window.location.reload();
  }
}

// Get new word
function newWord() {
  const inputWord = input.value;

  if(inputWord === randomWord && inputWord !== '') {
    totalScore++;
    updateTime();
    randomWord = getRandomWord();
    input.value = '';
    populateUI(randomWord, totalScore, timeLeft);
  }
}

// Update time
function updateTime() {
  if(selectList.value === 'easy') {
    timeLeft += 3;
  } else if(selectList.value === 'medium') {
    timeLeft += 2;
  } else {
    timeLeft += 1;
  }
}

// Get Random Word
function getRandomWord() {
  const word = words[Math.floor(words.length * Math.random())];
  return word;
}

// Populate UI
function populateUI(word, score, time) {
  uiWord.innerText = word;
  uiTime.innerText = time;
  uiScore.innerText = score;
}


// App
populateUI(randomWord, totalScore, timeLeft);


// Event Listeners
settings.addEventListener('click', () => navbar.classList.toggle('show'));

rulesBtn.addEventListener('click', () => rulesContainer.classList.add('show'));

closeBtn.addEventListener('click', () => rulesContainer.classList.remove('show'));

startBtn.addEventListener('click', startGame);

selectList.addEventListener('change', updateDifficulty);

input.addEventListener('input', newWord);

card.addEventListener('click', replayGame);