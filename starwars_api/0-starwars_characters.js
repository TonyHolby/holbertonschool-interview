#!/usr/bin/node
const request = require('request');

if (process.argv.length < 3) {
  process.exit(1);
}

const movieNumber = process.argv[2];
const urlPath = 'https://swapi-api.hbtn.io/api/films/' + movieNumber;

function requestPromise (url) {
  return new Promise((resolve, reject) => {
    request(url, (err, res, body) => {
      if (err) return reject(err);
      if (res.statusCode !== 200) { return reject(new Error(`Status code: ${res.statusCode}`)); }
      resolve(body);
    });
  });
}

async function main () {
  const body = await requestPromise(urlPath);
  const movie = JSON.parse(body);

  for (const charUrl of movie.characters) {
    const charBody = await requestPromise(charUrl);
    const character = JSON.parse(charBody);
    console.log(character.name);
  }
}

main();
