import React from "react"
import { Switch, Route } from 'react-router-dom'

import AlgorithmVisualizer from "../AlgorithmVisualizer"
import { ErrorMessage }    from "../Helpers"
import CardToSubTopics     from "./CardToAlgorithms"
import TopicsData          from "../../Data/TopicsData"

/**
   * Find if the topic link is valid, and then choose if we should call the 
   * CardToSubTopics of the AlgorithmVisualizer.
   * 
   * @param TopicData The Topic
   */
const AlgorithmPicker: React.FunctionComponent<{TopicLink: string}> = props => {
	const TopicData = TopicsData.find(Topic => Topic.link === props.TopicLink)
	if (!TopicData) return <ErrorMessage />

	return (
		<Switch>
			<Route 
				exact path = {`/Topic/${TopicData.link}/`}
				render     = { () => <CardToSubTopics TopicData={TopicData} /> }
			/>
			<Route 
				path       = {`/Topic/${TopicData.link}/:Algorithm/`}
				render     = { props => {
					const AlgorithmData = TopicData.Algorithms.find( 
						Algorithm => Algorithm.link ===  props.match.params.Algorithm
					)
					
					if (!AlgorithmData) return <ErrorMessage />
					return <AlgorithmVisualizer AlgorithmData={AlgorithmData} TopicLink={TopicData.link} />
				}}
			/>
		</Switch>
	)
  
}

export default AlgorithmPicker