import React from "react"
import ReactDOM from "react-dom"
import {HashRouter, Switch, Route} from 'react-router-dom'

import Header from "./Header"
import Footer from "./Footer"

import Home from "./Home"

const TopicVisualizer = React.lazy(() => import('./TopicVisualizer'))

const App: React.StatelessComponent<{}> = () => (
	<React.Fragment>
		<header>
			<Header />
			<br />
		</header>

		<main>
			<Switch>
				<Route 
					exact  = {true}
					path   = '/'
					render = { () => <Home /> }
				/>
				<Route
					path   = '/Topic/:NameOfTopic'
					render = { (props) => {
						console.log("Lo logre :)")
						return (
							<React.Suspense fallback={<div>Loading...</div>}>
								<TopicVisualizer match={props.match} /> 
							</React.Suspense>
						)
					}
					}
				/>
			</Switch>
			<br />
			<br />
			<br />
		</main>

		<Footer />
		
	</React.Fragment>
)

ReactDOM.render(<HashRouter><App /></HashRouter>, document.getElementById('ReactApp'))