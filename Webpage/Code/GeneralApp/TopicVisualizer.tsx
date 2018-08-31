import React from "react"
import { Link, Switch, Route } from 'react-router-dom'

import AlgorithmVisualizer from "../AlgorithmVisualizer"
import Topics from "../Data"
import { Topic } from "../Data/DataType";

const ErrorMessage: React.StatelessComponent<{}> = () => {

	return (
		<div className="container">
			<div className="row">
				<div className="col s12">
					<div className="card-panel">
						
						<div className="center">
							<h4 className="blue-grey-text text-darken-3">
								Error, Something did not go right. Sorry :(
							</h4>
							<br />
							<br />
						</div>

					</div>
				</div>
			</div>

			<br /><br /><br /><br />
			<br /><br /><br /><br />
			<br /><br /><br /><br />
			<br /><br /><br /><br />
			<br /><br /><br /><br />

		</div>
	)
}


const cardOfSubTopics: React.StatelessComponent<{Topic: Topic}> = (props: {Topic: Topic}) => {

	const colors: Array<string> = [
		"red lighten-2",
		"indigo lighten-2",
		"cyan lighten-1",
		"green lighten-2",
		"orange lighten-2",
		"brown lighten-2",
	].sort(() => Math.random() - 0.5)

	return (
		<div className="container">
			<div className="row">
				<div className="col s12">
					<div className="card-panel">
						
						<div className="center">

							<h4 className="blue-grey-text text-darken-3">
								{props.Topic.name}
							</h4>

							<br />
							<br />
						
						</div>

						{
							props.Topic.subTopics.map( (SubTopic, subTopicsIndex) =>  {
								let buttonStyle = "hoverable btn-large col s12 m8 l6 offset-m2 offset-l3"
								buttonStyle = `${buttonStyle} ${colors[subTopicsIndex % colors.length]}`

								return (
									<div className="row" key={SubTopic.link}>
										<Link 
											className	= {buttonStyle}
											to				= {`/Topic/${props.Topic.link}/${SubTopic.link}`}
										>
											{SubTopic.name}
										</Link>
									</div>
								)
							}
						)
					}

					</div>
				</div>
			</div>

			<br />
			<br />
			<br />
			<br />
			<br />

		</div>

	)
}

// TODO: Do this great
const TopicVisualizer: React.StatelessComponent<{}> = () => {

	const Topic = Topics.find( Topic => Topic.link === props.match.params.NameOfTopic)
	if (Topic == undefined) return <ErrorMessage />

	return (
		<Switch>
			<Route 
				exact path = {`/Topic/${Topic.Link}/`}
				render     = { (props) => <cardOfSubTopics {...props} Topic={Topic} /> }
			/>
			<Route 
				path   = {`/Topic/${Topic.Link}/:Algorithm/`}
				render = { 
					(props) => {
						const AlgorithmData = Topic.SubTopics.find( SubTopic => SubTopic.Link ===  props.match.params.Algorithm)
						return <AlgorithmVisualizer {...props} Algorithm={AlgorithmData} Topic={Topic} key={Date.now()} />
					}

				}
			/>
		</Switch>
	)
  
}


export default TopicVisualizer
