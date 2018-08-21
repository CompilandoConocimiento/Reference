// ======================================================================
// ============          WEB APP IN REACT           =====================
// ======================================================================

import React from "react"
import ReactDOM from "react-dom"
import { HashRouter, Switch, Route } from 'react-router-dom'

import Header from "./Header"
import Footer from "./Footer"

import Home from "./Home"
import TopicVisualizer from "./TopicVisualizer"

function App (props) {

    return (
        <React.Fragment>
            
            <Header />

            <main>
                <br />
                <br />

                <Switch>
                    
                    <Route 
                        exact  = {true}
                        path   = '/'
                        render = { (props) => <Home {...props} /> }
                    />
                    
                    <Route 
                        path   = '/Topic/:NameOfTopic'
                        render = { (props) => <TopicVisualizer {...props} /> }
                    />
                
                </Switch>

                <br />
                <br />
                <br />
            </main>

            <Footer />

        </React.Fragment>
    )
}

ReactDOM.render(<HashRouter><App /></HashRouter>, document.getElementById('ReactApp'))