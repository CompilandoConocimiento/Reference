import React, { FunctionComponent } from "react"
import { RouteComponentProps } from "react-router"
import { withRouter } from "react-router-dom"

import { Paper, Button, Typography } from "@material-ui/core"

import useCardStyles from "./Styles"

interface CardProps {
  name: string
  backgroundColor: string
  routeLink: string
}

type CardToTopicType = FunctionComponent<CardProps & RouteComponentProps>
const CardToTopic: CardToTopicType = ({ backgroundColor, name, history, routeLink }) => {
  const link = () => history.push(`/Topic/${routeLink}/`)
  const Styles = useCardStyles()

  return (
    <Paper className={Styles.Card} style={{ backgroundColor }} onClick={link}>
      <Typography className={Styles.Text} gutterBottom variant="h4">
        {name}
      </Typography>
      <div className={Styles.Divider} />
      <Button className={Styles.Text} size="medium" color="primary">
        CHECK IT OUT!
      </Button>
    </Paper>
  )
}

export default withRouter(CardToTopic)
