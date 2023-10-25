if ("geolocation" in navigator) {
    navigator.geolocation.getCurrentPosition(function (position) {
        const latitude = position.coords.latitude;
        const longitude = position.coords.longitude;
    });
} else {
    console.log("Geolocation is not available in this browser.");
}