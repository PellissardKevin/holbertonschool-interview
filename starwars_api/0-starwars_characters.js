#!/usr/bin/node

const request = require('request');

// Base URL for the Star Wars API
const BASE_URL = 'https://swapi.dev/api/films/';

function fetchCharacter(movieId) {
  const movieURL = `${BASE_URL}${movieId}/`;

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

    // Function to fetch a single character
    function fetchCharacterData(url) {
      return new Promise((resolve, reject) => {
        request(url, { json: true }, (error, response, body) => {
          if (error) {
            reject(`Error fetching character data: ${error.message}`);
            return;
          }

          if (response.statusCode !== 200) {
            reject(`Failed to fetch character from ${url}: ${response.statusCode}`);
            return;
          }

          resolve(body.name);
        });
      });
    }

    // Fetch characters sequentially
    (async function fetchAllCharacters() {
      for (const url of characterUrls) {
        try {
          const name = await fetchCharacterData(url);
          console.log(name);
        } catch (error) {
          console.error(error);
        }
      }
    })();
  });
}

// Check command-line arguments
const movieId = process.argv[2];

if (!movieId) {
  console.log('Please provide a movie ID as the first argument.');
  process.exit(1);
}

if (isNaN(movieId)) {
  console.log('Movie ID must be an integer.');
  process.exit(1);
}

fetchCharacter(movieId);
