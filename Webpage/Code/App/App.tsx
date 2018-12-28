import React from "react"
import ReactDOM from "react-dom"
import { HashRouter, Switch, Route } from 'react-router-dom'

import Header from "./Header"
import Footer from "./Footer"

import Home from "./Home"
import { Loading } from "./Helpers"
const SubTopicsPicker = React.lazy(() => import('./SubTopicsPicker'))

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
					render = { props => 
						<React.Suspense fallback={<Loading />}>
							<SubTopicsPicker TopicLink={props.match.params.TopicLink as string} /> 
						</React.Suspense>
					}
				/>
				<Route path='/:SomethingElse' component={Home}/>
			</Switch>
		</main>

		<Footer />
		
	</React.Fragment>
)

ReactDOM.render(<HashRouter><App /></HashRouter>, document.getElementById('ReactApp'))