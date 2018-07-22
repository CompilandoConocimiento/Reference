// ======================================================================
// ============          WEB APP IN REACT           =====================
// ======================================================================

/* ========= BASIC REACT THINGS ===============*/
import React from "react"
import ReactDOM from "react-dom"
import { HashRouter, Switch, Route } from 'react-router-dom'

/* ========= MATERIALIZCE CSS =================*/
import M from "materialize-css"
import "materialize-css/dist/css/materialize.min.css"

/* ========= THE COMPONENTS ==================*/
import AppHeader from "./AppHeader"
import Home from "./Home"
import TopicVisualizer from "./TopicVisualizer"
import Footer from "./Footer"

// =====================================================================
// ============              APP COMPONENTS        =====================
// =====================================================================
class App extends React.Component {

    constructor(props) {super(props)}

    render () {

        return (
            <React.Fragment>
                
                <AppHeader />

                <main>
                    <br />
                    <Switch>
                        <Route exact path='/' render={ (props) => <Home {...props} /> } />
                        <Route path='/Topic/:NameOfTopic' render={ (props) => <TopicVisualizer {...props} /> } />
                    </Switch>
                    <br />
                    <br />
                    <br />
                </main>

                <Footer />

            </React.Fragment>
        )
    }
}

ReactDOM.render((<HashRouter><App /></HashRouter>), document.getElementById('ReactApp'))