#!/usr/bin/env node

const request = require("request");

// Base URL for the Star Wars API
const BASE_URL = 'https://swapi.dev/api/films/';

function fetchCharacter(movieId) {
  const movieURL = `${BASE_URL}${movieId}`;

  request(movieURL, { json: true }, (error, response, body) => {
    if (error) {
      console.error('Error fetching data:', error.message);
      return;
    }

    // Check if the movie was found
    if (response.statusCode !== 200) {
      console.log(`Movie with ID ${movieId} not found.`);
      return;
    }

    // Extract the character URLs
    const characterUrls = body.characters;

    // Loop through the character URLs and fetch their names
    characterUrls.forEach((url) => {
      request(url, { json: true }, (error, response, body) => {
        if (error) {
          console.error('Error fetching character data:', error.message);
          return;
        }

        console.log(body.name);
      });
    });
  });
}


const movieId = process.argv[2]

if (!movieId) {
  console.log('Please provide a movie ID as the first argument.')
}
else {
  fetchCharacter(movieId);
}
