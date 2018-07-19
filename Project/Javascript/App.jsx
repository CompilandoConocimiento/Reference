// ======================================================================
// ============          WEB APP IN REACT           =====================
// ======================================================================

/* ========= BASIC REACT THINGS ===============*/
import React from "react"
import ReactDOM from "react-dom"
import { HashRouter } from 'react-router-dom'

/* ========= MATERIALIZCE CSS =================*/
import M from "materialize-css"
import "materialize-css/dist/css/materialize.min.css"

/* ========= THE COMPONENTS ==================*/
import {Data} from "./Data"
import AppHeader from "./AppHeader"
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
						Data = {Data.SideMenu} 
					/>
				</header>

				<Switch>
					<Route exact path='/' component={Home}/>
					<Route path='/roster' component={Roster}/>
					<Route path='/schedule' component={Schedule}/>
				</Switch>


				<main>
					<br />
					<br />
				</main>

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