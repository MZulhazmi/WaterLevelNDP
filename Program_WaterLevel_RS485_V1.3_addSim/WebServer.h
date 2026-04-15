
// ========================================
// HTML INTERFACE DALAM PROGMEM
// ========================================

const char main_page_html[] PROGMEM = R"rawliteral(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Water Level Settings</title>
        <style>
            body {
            font-family: Arial, sans-serif;
            max-width: 600px;
            margin: 0 auto;
            padding: 20px;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            }
            .container {
            background: white;
            padding: 30px;
            border-radius: 10px;
            box-shadow: 0 10px 25px rgba(0,0,0,0.2);
            }
            h1 {
            color: #333;
            text-align: center;
            margin-bottom: 30px;
            }
            .form-group {
            margin-bottom: 20px;
            }
            label {
            display: block;
            margin-bottom: 8px;
            color: #555;
            font-weight: bold;
            }
            input[type="number"] {
            width: 100%;
            padding: 10px;
            border: 2px solid #ddd;
            border-radius: 5px;
            font-size: 16px;
            box-sizing: border-box;
            transition: border-color 0.3s;
            }
            input[type="number"]:focus {
            outline: none;
            border-color: #667eea;
            }
            .button-group {
            display: flex;
            gap: 10px;
            margin-top: 30px;
            }
            button {
            flex: 1;
            padding: 12px;
            font-size: 16px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-weight: bold;
            transition: transform 0.2s;
            }
            .btn-save {
            background: #667eea;
            color: white;
            }
            .btn-save:hover {
            background: #5568d3;
            transform: translateY(-2px);
            }
            .btn-cancel {
            background: #ddd;
            color: #333;
            }
            .btn-cancel:hover {
            background: #ccc;
            transform: translateY(-2px);
            }
            .info {
            background: #f0f0f0;
            padding: 15px;
            border-radius: 5px;
            margin-bottom: 20px;
            border-left: 4px solid #667eea;
            }
            .status {
            text-align: center;
            margin-top: 20px;
            padding: 10px;
            border-radius: 5px;
            display: none;
            }
            .status.success {
            background: #d4edda;
            color: #155724;
            display: block;
            }
            .status.error {
            background: #f8d7da;
            color: #721c24;
            display: block;
            }
        </style>
        </head>
        <body>
        <div class="container">
            <h1>Water Level Settings</h1>
            <div class="info">
            <strong>Configure Calibration Settings</strong>
            </div>
            <form id="settingsForm">
            <div class="form-group">
                <label for="calibM">Calibration M (Multiplier):</label>
                <input type="number" id="calibM" name="calibM" value="1" required>
            </div>
            <div class="form-group">
                <label for="calibC">Calibration C (Constant):</label>
                <input type="number" id="calibC" name="calibC" value="0" required>
            </div>
            <div class="form-group">
                <label for="interval">Interval (minutes):</label>
                <input type="number" id="interval" name="interval" value="15" required min="1">
            </div>
            <div class="button-group">
                <button type="button" class="btn-save" onclick="saveSettings()">Save</button>
                <button type="button" class="btn-cancel" onclick="cancelSettings()">Cancel</button>
            </div>
            <div id="status" class="status"></div>
            </form>
        </div>
        <script>
            function saveSettings() {
            const calibM = document.getElementById('calibM').value;
            const calibC = document.getElementById('calibC').value;
            const interval = document.getElementById('interval').value;
            
            fetch('/savesettings', {
                method: 'POST',
                headers: {'Content-Type': 'application/x-www-form-urlencoded'},
                body: `calibM=${calibM}&calibC=${calibC}&interval=${interval}`
            })
            .then(response => response.text())
            .then(data => {
                const status = document.getElementById('status');
                if(data.includes('success')) {
                status.className = 'status success';
                status.textContent = 'Settings saved successfully!';
                setTimeout(() => window.close(), 1500);
                } else {
                status.className = 'status error';
                status.textContent = 'Error saving settings';
                }
            });
            }
            
            function cancelSettings() {
            window.close();
            }
        </script>
    </body>
    </html>
)rawliteral";