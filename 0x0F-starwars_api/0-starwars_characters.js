#!/usr/bin/node

const request = require('request');
const ac = process.argv.slice(2);

request.get(`https://swapi-api.hbtn.io/api/films/${ac}/`, async (_error, response, body) => {
  const details = JSON.parse(body);
  for (const characters of details.characters) {
    request.get(characters, async (errors, response, body) => {
      const character = JSON.parse(body);
      console.log(character.name);
    });
  }
});
