//<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
$.ajax({
    type: 'POST',
    url: 'test.php',
    data: formData,
    contentType: false,
    processData: false,
    success: function(response) {
      console.log(response) // json
    }
  });