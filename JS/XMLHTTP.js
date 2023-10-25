var xhr = new XMLHttpRequest();
xhr.open('POST', 'test.php')
xhr.setRequestHeader('Content-Type', 'application/json');
xhr.onreadystatechange = function () {
if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
    let res = xhr.responseText
    console.log(res)
}
};
xhr.send(JSON.stringify());

var response = JSON.parse(xhr.responseText); //cover json

const xhr = new XMLHttpRequest();
xhr.open('GET', 'test.php', true);
xhr.onreadystatechange = function () {
    if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
        var res = xhr.responseText;
    }
};
xhr.send();