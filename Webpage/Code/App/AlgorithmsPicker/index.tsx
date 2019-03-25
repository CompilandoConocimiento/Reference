import React, { FunctionComponent } from "react"
import { Switch, Route } from "react-router-dom"

import AlgorithmVisualizer from "../AlgorithmVisualizer"
import { ErrorMessage } from "../Helpers"
import CardToSubTopics from "./CardToAlgorithms"
import { TopicData } from "../../Data"

/**
 * Find if the topic link is valid, and then choose if we should call the
 * CardToSubTopics of the AlgorithmVisualizer.
 *
 * @param TopicData The Topic
 */
const AlgorithmsPicker: FunctionComponent<{ TopicData: TopicData }> = ({TopicData}) => {
  const baseLink = `/Topic/${TopicData.link}/`
  const CardToSubTopic = () => <CardToSubTopics {...{baseLink, TopicData}} />
  return (
    <Switch>
      <Route exact path={baseLink} render={CardToSubTopic} />
      <Route
        path={baseLink + `:algorithm/`}
        render={props => {
          const AlgorithmData = TopicData.Algorithms.find(
            algorithm => algorithm.link === props.match.params.algorithm
          )

          if (!AlgorithmData) return <ErrorMessage />
          return <AlgorithmVisualizer AlgorithmData={AlgorithmData} TopicLink={TopicData.link} />
        }}
      />
    </Switch>
  )
}

export default AlgorithmsPicker
