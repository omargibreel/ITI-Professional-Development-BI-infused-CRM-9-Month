var cookieLib = {
    setCookie: function (name, value) {
        var d = new Date();
        d.setMonth(d.getMonth() + 1);
        document.cookie = name + "=" + value + ";expires=" + d.toUTCString() + ";path=/";
    },
    getCookie: function (name) {
        var cookieArray = document.cookie.split(";");
        for (var i = 0; i < cookieArray.length; i++) {
            var pair = cookieArray[i].trim().split("=");
            if (pair[0] === name) return pair[1];
        }
        return "";
    }
};