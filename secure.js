const express = require('express');
const app = express();
const path = require('path');
const bodyParser = require('body-parser');

// Middleware for parsing form data
app.use(bodyParser.urlencoded({ extended: true }));

// Serve the HTML file
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'secureIPC.html'));
});

// Handle POST request from the form
app.post('/process_message', (req, res) => {
    const username = req.body.username;
    const password = req.body.password;
    const message = req.body.message;

    // Check user authentication
    if ((username === 'user1' && password === 'user@001') || (username === 'user2' && password === 'user@002')) {
        const encryptedMessage = encryptMessage(message);
        const decryptedMessage = decryptMessage(encryptedMessage);

        res.send(`
            <h2>Result</h2>
            <p><strong>Encrypted Message:</strong> ${encryptedMessage}</p>
            <p><strong>Decrypted Message:</strong> ${decryptedMessage}</p>
            <a href="/">Back to Home</a>
        `);
    } else {
        res.send('Authentication Failed! <a href="/">Try again</a>');
    }
});

// Simple encryption and decryption functions
function encryptMessage(message) {
    const secretKey = 'Security789@';
    return message.split('').map((char, i) => String.fromCharCode(char.charCodeAt(0) ^ secretKey[i % secretKey.length].charCodeAt(0))).join('');
}

function decryptMessage(encryptedMessage) {
    const secretKey = 'Security789@';
    return encryptedMessage.split('').map((char, i) => String.fromCharCode(char.charCodeAt(0) ^ secretKey[i % secretKey.length].charCodeAt(0))).join('');
}

// Start the server
app.listen(3000, () => {
    console.log('Server running at http://localhost:3000');
});
