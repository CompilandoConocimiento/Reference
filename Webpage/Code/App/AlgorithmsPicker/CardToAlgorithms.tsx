import React from "react"
import { Link } from "react-router-dom"

import { Paper, Box, Typography, Button } from "@material-ui/core"

import { toTop as onClick } from "../Helpers"
import { TopicData } from "../../Data/Types"

import useCardStyle from "./Styles"
import { Colors } from "../App/Styles"

/**
 * Render a list of buttons of a given topic.
 * @param TopicData The Topic
 */
const CardOfSubTopics: React.FunctionComponent<{
  TopicData: TopicData
  baseLink: string
}> = props => {
  const Styles = useCardStyle()
  return (
    <Paper className={Styles.Paper}>
      <Typography gutterBottom variant="h4">
        <Box fontWeight={500}>{props.TopicData.name}</Box>
      </Typography>
      <br />

      {props.TopicData.Algorithms.map(({ link, name }, index) => {
        const style = { backgroundColor: Colors[index % Colors.length] }
        const to = props.baseLink + link
        const buttonsProps = { to, onClick, style, component: Link }

        return (
          <Button variant="contained" key={name} className={Styles.Button} {...buttonsProps}>
            {name}
          </Button>
        )
      })}
    </Paper>
  )
}

export default CardOfSubTopics
