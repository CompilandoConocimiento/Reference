import React, { FunctionComponent, Suspense } from "react"

import { Typography, Box } from "@material-ui/core"

import { AlgorithmData } from "../../Data/Types"
import { Loading } from "../Helpers"

import useStyles from "./Styles"

interface VisualizerProps {
  AlgorithmData: AlgorithmData
  TopicLink: string
}

const AlgorithmVisualizer2: FunctionComponent<VisualizerProps> = ({ AlgorithmData, TopicLink }) => {
  const Styles = useStyles()
  return (
    <React.Fragment>
      <div className={Styles.ArticleTitle}>
        <Typography gutterBottom variant="h4">
          <Box fontWeight={500}>{AlgorithmData.name}</Box>
        </Typography>
      </div>
      <div className={Styles.ArticleBody}>
        <Suspense fallback={<Loading />}>
          <AlgorithmData.Component />
        </Suspense>
      </div>
    </React.Fragment>
  )
}

export default AlgorithmVisualizer2
