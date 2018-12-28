import React from "react"
import { Switch, Route } from 'react-router-dom'

import AlgorithmVisualizer from "../../AlgorithmVisualizer"
import { ErrorMessage }    from "../Helpers"
import CardToSubTopics     from "./CardToSubTopics"
import { DirectoryData }   from "../../Data"

const SubTopicsPicker: React.FunctionComponent<{TopicLink: string}> = props => {
	const DirectoryTopic = DirectoryData.find( Topic => Topic.link === props.TopicLink)
	if (!DirectoryTopic) return <ErrorMessage />

	return (
		<Switch>
			<Route 
				exact path = {`/Topic/${DirectoryTopic.link}/`}
				render     = { () => <CardToSubTopics DirectoryTopic={DirectoryTopic} /> }
			/>
			<Route 
				path       = {`/Topic/${DirectoryTopic.link}/:Algorithm/`}
				render     = { props => {
					const AlgorithmData = DirectoryTopic.subTopics.find( SubTopic => SubTopic.link ===  props.match.params.Algorithm)
					return <AlgorithmVisualizer Algorithm={AlgorithmData!} Topic={DirectoryTopic} key={Date.now()} />
				}}
			/>
		</Switch>
	)
  
}

export default SubTopicsPicker