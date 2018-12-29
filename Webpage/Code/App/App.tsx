import React from "react"
import ReactDOM from "react-dom"
import { HashRouter, Switch, Route } from 'react-router-dom'

import Header from "./Header"
import Footer from "./Footer"
import Home from "./Home"
import AlgorithmsPicker from "./AlgorithmsPicker"

/**
   * This is a wrapper of all the app, the header, the footer and
   * the content.
   */
const App: React.FunctionComponent = () => (
	<React.Fragment>
		<header>
			<Header />
			<br />
		</header>

		<main>
			<Switch>
				<Route exact path='/' component={Home}/>
				<Route path='/Topic/:TopicLink'
					render = { 
						props => <AlgorithmsPicker TopicLink={props.match.params.TopicLink} /> 
					}
				/>
				<Route path='/:SomethingElse' component={Home}/>
			</Switch>
		</main>

		<Footer />
		
	</React.Fragment>
)

ReactDOM.render(<HashRouter><App /></HashRouter>, document.getElementById('ReactApp'))