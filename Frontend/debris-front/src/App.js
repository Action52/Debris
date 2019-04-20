import React, { Component } from 'react';
import logo from './logo.png';
import './App.css';
import Form from 'react-bootstrap/Form';
class App extends Component {
  render() {
    return (
      <div className="App">
        <header className="App-header">
          <Form.Control size="lg" type="text" placeholder="Large text" />
          <br />
          <Form.Control type="text" placeholder="Normal text" />
          <br />
          <Form.Control size="sm" type="text" placeholder="Small text" />
        </header>
      </div>
    );
  }
}

export default App;
