//----------------------
// ES6 - Promise
//----------------------

//The Promise object represents the eventual 
//completion (or failure) of an asynchronous
// operation and its resulting value.

//States:

//pending: initial state, neither fulfilled nor rejected.
//fulfilled: meaning that the operation was completed successfully.
//rejected: meaning that the operation failed.


const urls = [
  'https://jsonplaceholder.typicode.com/users',
  'https://jsonplaceholder.typicode.com/posts',
  'https://jsonplaceholder.typicode.com/albums'
]

Promise.all(urls.map(url => {
  fetch(url).then(resp => resp.json())
})).then(result => {
  console.log(result[0])
  console.log(result[1])
  console.log(result[2])
}).catch(() => console.log('error'))
