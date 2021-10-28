import logo from './logo.svg';
import cpLogo from './Cyberpunk-logo.png';
import './App.css';
import 'bootstrap/dist/css/bootstrap.css';
import { Button } from 'react-bootstrap';
import React from 'react';
import { render } from 'react-dom';

class App extends React.Component {
  callBackend() {
    let xhttp = new XMLHttpRequest()
    xhttp.open('GET', 'http://localhost:5000/start')
    xhttp.send()
  }

  render() {
    return (
    <div className="App" id="main-bg">
      <div class="container logo-spread">
        <div class="row">
          <div class="col">
            <img src={cpLogo} class="cyberpunk-bg" id="top-cyberpunk-img" alt="Cyberpunk Logo"></img>
          </div>
        </div>
        <div class="row">
          <div class="col">
            <img src={cpLogo} class="cyberpunk-bg" alt="Cyberpunk Logo"></img>
          </div>
        </div>
        <div class="row">
          <div class="col">
            <img src={cpLogo} class="cyberpunk-bg" alt="Cyberpunk Logo"></img>
          </div>
        </div>
        <div class="row">
          <div class="col">
            <img src={cpLogo} class="cyberpunk-bg" id="bottom-cyberpunk-img" alt="Cyberpunk Logo"></img>
          </div>
        </div>
        <div class="row">
          <div class="col">
            <img src={cpLogo} class="cyberpunk-bg" id="bg-img-main" alt="Cyberpunk Logo"></img>
          </div>
        </div>
      </div>
      <div class="container">
        <div class="row">
          <div class="col"></div>
          <div class="col-8">
            <img src={cpLogo} height="225" class="logo" alt="Cyberpunk Logo"></img>
          </div>
        </div>
        <div class="row" id="break-row">
          <div class="col"></div>
          <div class="col">
            <hr id="logo-break"></hr>
          </div>
          <div class="row" id="break-row">
            <div class="col"></div>
            <div class="col">
              <hr id="logo-break"></hr>
            </div>
          </div>
          <div class="row">
            <div class="col-6" id="description-txt">
              <h2 class="header">Description</h2>
              <h4 id="description">The robotic arm will be picking up an object and moving it another position. 
                After moving the object to another position it will place the object onto the landing surface and let it go.
                Next, it will pick the object back up from the landing surface and move it to its original position on the landing surface.
                Lastly, it will place the object in the hole. </h4>
            </div>
            <div class="col-6">
              <h2 class="header">Terminal Commands</h2>
              <div class="terminal-window">
                <p id="output-text">Performing gripper test in position...
                  <br></br>Going to position 0.30...
                  <br></br>Sending the twist command for 5 seconds...
                  <br></br>Sending the twist command for 5 seconds...
                  <br></br>Stopping the robot...
                  <br></br>Sending the twist command for 5 seconds...
                  <br></br>Sending the twist command for 5 seconds...
                  <br></br>Stopping the robot...
                  <br></br>Performing gripper test in position...
                  <br></br>Going to position 0.00...
                  <br></br>Moving the arm to a safe position
                  <br></br>EVENT: ACTION_START
                  <br></br>EVENT: ACTION_END
                  <br></br>Safe position reached
                </p>
              </div>
            </div>
          </div>
        </div>
        <div class="row">
          <div class="col-5" id="start-button-col">
            <h2 class="header">Click Start to Begin</h2>
            <button type="button" class="btn btn-light" onClick={this.callBackend}>Start</button>
          </div>
        </div>
      </div>
      </div>
    );
  }
}

export default App;
