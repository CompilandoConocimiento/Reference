import React, {FunctionComponent} from "react"
import { withRouter } from "react-router-dom"
import Card from "@material-ui/core/Card"
import CardContent from "@material-ui/core/CardContent"
import Button from "@material-ui/core/Button"
import Typography from "@material-ui/core/Typography"
import { RouteComponentProps } from "react-router"

import useCardStyles from "./Styles"

interface CardProps {
  name: string
  backgroundColor: string
  routeLink: string
}

type CardToTopicType = FunctionComponent<CardProps & RouteComponentProps>
const CardToTopic: CardToTopicType = ({
  backgroundColor,
  name,
  history,
  routeLink,
}) => {
  const link = () => history.push(`/Topic/${routeLink}/`)
  const Styles = useCardStyles()

  return (
    <Card className={Styles.Card} style={{ backgroundColor }} onClick={link}>
      <CardContent>
        <Typography className={Styles.Text} gutterBottom variant="h4">
          {name}
        </Typography>
        <div className={Styles.Divider} />
        <Button className={Styles.Text} size="medium" color="primary">
          CHECK IT OUT!
        </Button>
      </CardContent>
    </Card>
  )
}

export default withRouter(CardToTopic)
