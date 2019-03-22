import React from "react"
import { Link } from "react-router-dom"

import { TopicData } from "../../Data/"

const colors = [
  "red lighten-2",
  "indigo lighten-2",
  "cyan lighten-1",
  "green lighten-2",
  "orange lighten-2",
  "brown lighten-2",
].sort(() => Math.random() - 0.5)

const buttonClassname = "hoverable btn-large col s12 m8 l6 offset-m2 offset-l3 "

/**
 * Render a list of buttons of a given topic.
 * @param TopicData The Topic
 */
const CardOfSubTopics: React.FunctionComponent<{ TopicData: TopicData }> = props => (
  <div className="container">
    <div className="card-panel center">
      <h4 className="blue-grey-text text-darken-3">{props.TopicData.name}</h4>
      <br />
      <br />

      {props.TopicData.Algorithms.map((Algorithm, index) => (
        <div className="row" key={Algorithm.link}>
          <Link
            className={buttonClassname + colors[index % colors.length]}
            to={`/Topic/${props.TopicData.link}/${Algorithm.link}`}
            onClick={() => scroll(0, 0)}
          >
            {Algorithm.name}
          </Link>
        </div>
      ))}
    </div>
  </div>
)

export default CardOfSubTopics
