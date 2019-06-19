import React, { FunctionComponent } from "react"
import { Switch, Route } from "react-router-dom"

import CardToSubTopics from "./CardToAlgorithms"
import AlgorithmVisualizer from "../AlgorithmVisualizer"

import { ErrorMessage } from "../Helpers"
import { TopicData } from "../../Data/Types"

const TopicDataLinkContext = React.createContext("")

/**
 * Find if the topic link is valid, and then choose if we should call the
 * CardToSubTopics of the AlgorithmVisualizer.
 *
 * @param TopicData The Topic
 */
const AlgorithmsPicker: FunctionComponent<{ TopicData: TopicData }> = ({ TopicData }) => {
  const baseLink = `/Topic/${TopicData.link}/`
  const CardToSubTopic = () => <CardToSubTopics {...{ baseLink, TopicData }} />
  return (
    <Switch>
      <Route exact path={baseLink} render={CardToSubTopic} />
      <Route
        path={baseLink + `:algorithm/`}
        render={props => {
          const desired = props.match.params.algorithm
          const AlgorithmData = TopicData.Algorithms.find(algorithm => algorithm.link === desired)

          if (!AlgorithmData) return <ErrorMessage />
          return (
            <TopicDataLinkContext.Provider value={TopicData.link}>
              <AlgorithmVisualizer AlgorithmData={AlgorithmData} />
            </TopicDataLinkContext.Provider>
          )
        }}
      />
    </Switch>
  )
}

export { TopicDataLinkContext }
export default AlgorithmsPicker
