'use strict';
// console.log(document.querySelector('.message').textContent);

// document.querySelector('.message').textContent = 'correct';
// console.log(document.querySelector('.message').textContent);

// console.log(document.querySelector('.number').textContent);
// document.querySelector('.number').textContent = 12;
// console.log(document.querySelector('.number').textContent);

// document.querySelector('.guess').value = 2;

let secretnumber = Math.trunc(Math.random() * 20) + 1;
let score = 20;
document.querySelector('.check').addEventListener('click', function () {
  const guess = Number(document.querySelector('.guess').value);
  console.log(guess, typeof guess);

  // when no input

  if (!guess) {
    document.querySelector('.message').textContent =
      'r u chumtia or wot...No number 🌚';
  }

  //when payer wins
  else if (guess === secretnumber) {
    document.querySelector('.message').textContent = 'correct number';
    document.querySelector('body').style.backgroundColor = '#60b347';
    document.querySelector('.number').style.width = '30rem';
    document.querySelector('.number').textContent = secretnumber;
    let high = document.querySelector('.highscore').textContent;
    if (score > Number(high)) {
      document.querySelector('.highscore').textContent = score;
    }
  }

  // when too high or low
  else if (score > 0) {
    if (guess > secretnumber) {
      document.querySelector('.message').textContent = 'go below';
      //  const curscore = document.querySelector('.score').textContent;
      score--;
      document.querySelector('.score').textContent = score;
    } else if (guess < secretnumber) {
      document.querySelector('.message').textContent = 'go above';
      //  const curscore = document.querySelector('.score').textContent;
      score--;
      document.querySelector('.score').textContent = score;
    }
    if (score === 0)
      document.querySelector('.message').textContent = 'you lost noobde';
  }
});
document.querySelector('.again').addEventListener('click', function () {
  score = 20;
  document.querySelector('.message').textContent = 'Start guessing...';
  document.querySelector('.score').textContent = score;
  secretnumber = Math.trunc(Math.random() * 20) + 1;
  document.querySelector('.number').textContent = '?';
  document.querySelector('body').style.backgroundColor = 'black';
  document.querySelector('.number').style.width = '15rem';
  document.querySelector('.guess').value = '';
});
