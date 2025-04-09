<h1 align="center">🚗 Smart Parking System using IoT</h1>

<p align="center">
  A hardware + software IoT-based Parking Management System using <strong>Arduino</strong>, <strong>Python</strong>, and <strong>MySQL</strong>.<br>
  Automatically detects vehicles, allocates parking spots, controls entry/exit, and sends real-time WhatsApp notifications to users.
</p>

<hr>

<h2>📌 Project Highlights</h2>

<ul>
  <li>Real-time vehicle detection using ultrasonic sensors</li>
  <li>Automatic barrier control via Servo Motor and Arduino</li>
  <li>WhatsApp notifications for entry confirmation and billing</li>
  <li>MySQL database integration for storing user and parking records</li>
  <li>Dynamic billing system based on duration of parking</li>
  <li>Live parking status shown on LCD display</li>
</ul>

<hr>

<h2>🛠️ Tech Stack</h2>

<ul>
  <li><strong>Hardware:</strong> Arduino UNO, Ultrasonic Sensors, Servo Motor, LCD Display</li>
  <li><strong>Programming:</strong> C++ (Arduino), Python</li>
  <li><strong>Database:</strong> MySQL</li>
  <li><strong>Libraries:</strong> PyArduino, PyWhatKit, MySQL Connector</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>

<pre>
├── arduino_code.ino       # Arduino sketch: Sensor + Barrier control + LCD display
├── main.py                # Python script: DB communication, WhatsApp messaging
├── parking_system.sql     # (Optional) SQL file to initialize database
└── README.md              # This documentation
</pre>

<hr>

<h2>🚦 System Workflow</h2>

<ol>
  <li>Vehicle detected at entry via ultrasonic sensor</li>
  <li>Arduino triggers barrier and notifies Python via Serial</li>
  <li>Python script fetches user details from database</li>
  <li>WhatsApp message sent with allocated slot and time</li>
  <li>On exit, system calculates time spent and sends a billing message</li>
  <li>Amount is deducted from FASTag (simulated)</li>
</ol>

<hr>

<h2>📸 Demo Snapshots</h2>

<!-- Add your screenshots here -->
<p><em>(Insert images of working hardware, LCD display, WhatsApp messages, etc.)</em></p>

<hr>

<h2>🔧 Setup Instructions</h2>

<ol>
  <li>Connect Arduino UNO with sensors and servo motor as per the schematic</li>
  <li>Upload <code>arduino_code.ino</code> to Arduino using the Arduino IDE</li>
  <li>Install required Python packages:
    <pre><code>pip install pywhatkit mysql-connector-python</code></pre>
  </li>
  <li>Set up MySQL with required tables and data</li>
  <li>Run <code>main.py</code> and ensure Arduino is connected to the correct COM port</li>
</ol>

<hr>

<h2>💡 Features to Add</h2>

<ul>
  <li>Web-based dashboard for monitoring live slots</li>
  <li>QR code or RFID integration for user entry</li>
  <li>Dynamic slot allocation and map view</li>
  <li>Email alerts in addition to WhatsApp</li>
</ul>

<hr>

<h2>📬 Contact</h2>

<p>
  Created by <strong>Akshat Yadav</strong>.<br>
  For questions or collaboration, feel free to connect.
</p>

<hr>

<p align="center">
  ⭐ Star this repo if you found it useful &nbsp; | &nbsp; 🛠️ Contributions Welcome
</p>
