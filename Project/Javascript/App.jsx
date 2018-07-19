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
import {Data} from "./Data"
import AppHeader from "./AppHeader"
import Home from "./Home"
import Topic from "./Topic"
import Footer from "./Footer"

// =====================================================================
// ============              APP COMPONENTS        =====================
// =====================================================================
class App extends React.Component {

	constructor(props) {
		super(props)

	}

	render () {

		return (
			<React.Fragment>
				
				<header>
					<AppHeader
						Data = {Data.MiniData} 
					/>
				</header>

				<main>
                    <div className="container">
                        <br />
                        <Switch>
							<Route 
								exact path = '/' 
								render     = { (props) => <Home {...props} /> }
							/>
						  	<Route 
							  path   = '/Topic/:Topic'
							  render = { (props) => <Topic {...props} Data={Data.MiniData} /> }
							/>
                        </Switch>
                    </div>
                </main>

                <br /><br /><br />

				<footer>
					<Footer />
				</footer>

			</React.Fragment>
		)
	}
}

ReactDOM.render((
	<HashRouter>
	  <App />
	</HashRouter>
  ), document.getElementById('ReactApp'))