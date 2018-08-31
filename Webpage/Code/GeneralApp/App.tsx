import React from "react"
import ReactDOM from "react-dom"
import { HashRouter, Switch, Route } from 'react-router-dom'

import Header from "./Header"
import Footer from "./Footer"

import Home from "./Home"
import TopicVisualizer from "./TopicVisualizer"

const App: React.StatelessComponent<{}> = () => {

	return (
		<React.Fragment>
			
			<Header />

			<main>
				<br /><br />

				<Switch>
					
					<Route 
						exact  = {true}
						path   = '/'
						render = { () => <Home /> }
					/>
					
					<Route 
						path   = '/Topic/:NameOfTopic'
						render = { (props) => <TopicVisualizer match={props.match} /> }
					/>
				
				</Switch>

				<br /><br /><br />
			</main>

			<Footer />

		</React.Fragment>
	)
}

ReactDOM.render(<HashRouter><App /></HashRouter>, document.getElementById('ReactApp'))