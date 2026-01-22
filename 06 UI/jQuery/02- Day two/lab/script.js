$(document).ready(function () {
    function loadPosts(url) {
        $('#posts-container').html('');
        $('#post-count').text('0');

        $.get(url, function (posts) {
            $('#post-count').text(posts.length);

            for (var i = 0; i < posts.length; i++) {
                $('#posts-container').append(`
                    <div class="post-card">
                        <div class="post-title">${posts[i].title}</div>
                        <div class="post-body">${posts[i].body}</div>
                        <div class="post-meta">
                            <span>User ID: ${posts[i].userId}</span>
                            <span>Post ID: ${posts[i].id}</span>
                        </div>
                    </div>
                `);
            }
        });
    }

    $('#load-all').click(function () {
        console.log('Test');

        loadPosts('https://jsonplaceholder.typicode.com/posts');
    });

    $('#load-user1').click(function () {
        loadPosts('https://jsonplaceholder.typicode.com/posts?userId=1');
    });

    $('#load-user2').click(function () {
        loadPosts('https://jsonplaceholder.typicode.com/posts?userId=2');
    });
});