import React, { useContext } from "react"

import HelloCard from "./HelloCard"
import CardToTopic from "./CardToTopic"
import * as Style from "./Styles.css"

import { IndexDataContext } from "../App"

const radius = "1.15rem"

const colors = [
  "red lighten-2",
  "indigo lighten-2",
  "cyan lighten-1",
  "green lighten-2",
  "brown lighten-2",
].sort(() => Math.random() - 0.5)

const Home: React.FunctionComponent = () => {
  const IndexData = useContext(IndexDataContext)

  return (
    <div className="container">
      <HelloCard radius={radius} />

      <div className={Style.Wrapper}>
        {IndexData.map((Topic, index) => (
          <CardToTopic
            key={index}
            radius={radius}
            name={Topic.name}
            link={Topic.link}
            materializeCSSColor={colors[index % colors.length]}
          />
        ))}
      </div>
    </div>
  )
}

export default Home
