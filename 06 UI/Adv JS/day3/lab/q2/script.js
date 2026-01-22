var postsContainer = document.getElementById('posts-container');
var xhr = new XMLHttpRequest();

xhr.open('GET', 'https://jsonplaceholder.typicode.com/posts', true);

xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        var posts = JSON.parse(xhr.responseText);
        var cartona = '';
        for (var i = 0; i < 30; i++) {
            var post = posts[i];
            cartona += `
<article class="group bg-white p-8 rounded-2xl ">
    <div class="flex items-center gap-3 mb-4">
        <span class="flex h-8 w-8 items-center justify-center rounded-full ">
            ${post.id}
        </span>
        <span class="text-xs font-medium  ">
            Article
        </span>
    </div>

    <h2 class="text-xl font-bold text-slate-800  mb-3">
        ${post.title}
    </h2>

    <p class="text-slate-600 leading-relaxed">
        ${post.body}
    </p>

    <div class="mt-6 flex items-center">
        <a href="#" class="text-sm font-semibold ">
            Continue reading →
        </a>
    </div>
</article>
`;

        }

        postsContainer.innerHTML = cartona;
    } else if (xhr.readyState === 4 && xhr.status !== 200) {
        postsContainer.innerHTML = '<p class="text-red-500">Error loading data.</p>';
    }
};

xhr.send();