#!/usr/bin/node

const request = require('request');
const M_ID = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + M_ID;
const Dict = {};

request(url, function (err, res, body) {
  if (err) console.log(err);
  const characters = JSON.parse(body).characters;
  characters.forEach((char) => {
    request(char, function (err, res, body) {
      if (err) console.log(err);
      const name = JSON.parse(body).name;
      Dict[char] = name;
      if (Object.values(Dict).length === characters.length) {
        characters.forEach((character) => {
          console.log(Dict[character]);
        });
      }
    });
  });
});