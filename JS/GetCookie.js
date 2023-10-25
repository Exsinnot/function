function getCookieValue(cookieName) {
    let allCookies = document.cookie;
    let cookiesArray = allCookies.split('; ');
    for (let i = 0; i < cookiesArray.length; i++) {
        let cookie = cookiesArray[i].split('=');
        if (cookie[0] === cookieName) {
            return cookie[1];
        }
    }
    return null;
}
let username = getCookieValue('ZmVoSklGYWVqZmF3amRqa2xhd2hma29oYWpnd2dmYXdn23');

let expirationDate = new Date(); // create cookie
expirationDate.setDate(expirationDate.getDate() + 1);
document.cookie = "ZmVoSklGYWVqZmF3amRqa2xhd2hma29oYWpnd2dmYXdn23=true; expires=" + expirationDate.toUTCString() + "; path=/";
