import React from 'react';

export default function Square(props) {
  return (
    <button
      className={props.value ? 'btn disabled' : 'btn'}
      onClick={props.onClick}
    >
      {props.value}
    </button>
  );
}