
// Es6 lab day 2
// Promises
// a.Make your own interface to create tabs and display usernames by
// requesting users from the link below using Ajax ES6 fetch function:
//     https://jsonplaceholder.typicode.com/users
// Note: handle the response with promises using then and catch
// methods.

let usersContainer = document.querySelector(".users");
async function getUsers() {
    try {
        let response = await fetch("https://dummyjson.com/users");
        if (!response.ok) {
            throw "Failed to fetch users";
        }
        let result = await response.json();
        console.log(result);
        console.log(result.users);


        let cartona = "";
        result.users.forEach(user => {
            cartona += `
                <button class="user-btn" onclick="displayUserPosts(${user.id})">
                    ${user.firstName}
                </button>
            `;
        });
        usersContainer.innerHTML = cartona;
    } catch (error) {
        console.error("Error:", error);
    }
}
getUsers();


//     b.When a user tab is clicked display its posts’ titles by requesting the
// posts from the link below using Ajax ES6 fetch function:
//     https://jsonplaceholder.typicode.com/posts?userId=userId
// Note:
// - handle the response with promises using Async and await.
// - do not get the posts of all users on page load, the user tab must
// be clicked to request its posts.


let postsContainer = document.querySelector(".posts");

async function displayUserPosts(userId) {
    try {
        let response = await fetch(
            `https://dummyjson.com/posts/user/${userId}`
        );
        if (!response.ok) {
            throw "Failed to fetch posts";
        }
        let result = await response.json();

        let cartona = `<h2>Posts by User ${userId}</h2>`;
        result.posts.forEach(post => {
            cartona += `
                <div class="post">
                    ${post.title}
                </div>      
            `;
        });
        postsContainer.innerHTML = cartona;
    } catch (error) {
        console.error("Error:", error);
    }
}
