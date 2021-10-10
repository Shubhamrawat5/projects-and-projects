'strict';

// selecting elements
const player0el = document.querySelector('.player--0');
const player1el = document.querySelector('.player--1');
const score0el = document.querySelector('#score--0');
const score1el = document.getElementById('score--1'); //by both method we can select id
const cur0el = document.getElementById('current--0');
const cur1el = document.getElementById('current--1');
const diceel = document.querySelector('.dice');
const btnnew = document.querySelector('.btn--new');
const btnroll = document.querySelector('.btn--roll');
const btnhold = document.querySelector('.btn--hold');

let scores,
  cur_score,
  active_player = 0,
  playing;

// initializing conditon
const init = function () {
  scores = [0, 0];
  cur_score = 0;
  active_player = 0;
  playing = true;

  cur0el.textContent = 0;
  cur1el.textContent = 0;
  score0el.textContent = 0;
  score1el.textContent = 0;

  diceel.classList.add('hidden');
  player0el.classList.remove('player--winner');
  player1el.classList.remove('player--winner');
  player0el.classList.add('player--active');
  player1el.classList.remove('player--active');
};
init();

const switch_player = function () {
  document.getElementById(`current--${active_player}`).textContent = 0;
  active_player = active_player === 0 ? 1 : 0;
  cur_score = 0;
  player0el.classList.toggle('player--active');
  player1el.classList.toggle('player--active');
};
// rolling dice fucntionality
btnroll.addEventListener('click', function () {
  // genrating random number
  if (playing) {
    const dice = Math.trunc(Math.random() * 6) + 1;
    console.log(dice);

    // displaying dice number

    diceel.classList.remove('hidden');
    diceel.src = `dice-${dice}.png`;

    // if dice numbr is 1 then switvh to next plasyer else adding to current score
    if (dice !== 1) {
      // since not 1 adding to the current score
      cur_score += dice;
      document.getElementById(`current--${active_player}`).textContent =
        cur_score;
    } else {
      // switch to the next player
      switch_player();
    }
  }
});

btnhold.addEventListener('click', function () {
  // add current score to active player
  if (playing) {
    scores[active_player] += cur_score;
    document.getElementById(`score--${active_player}`).textContent =
      scores[active_player];
    // chk score ... if grater than 100 finish the game
    if (scores[active_player] >= 20) {
      // finshing the game
      playing = false;
      document
        .querySelector(`.player--${active_player}`)
        .classList.add('player--winner');
      document
        .querySelector(`.player--${active_player}`)
        .classList.remove('player--active');
    }
    // else switch to next player
    else switch_player();
  }
});

btnnew.addEventListener('click', init);
