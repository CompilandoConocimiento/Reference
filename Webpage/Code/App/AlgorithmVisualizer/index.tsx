import React, { FunctionComponent, Suspense } from "react"

import { Typography, Box } from "@material-ui/core"
import { AlgorithmData } from "../../Data/Types"
import { Loading } from "../Helpers"

import FAB from "./FAB"
import useStyles from "./Styles"

type AlgorithmVisualizerType = FunctionComponent<{ AlgorithmData: AlgorithmData }>
const AlgorithmVisualizer: AlgorithmVisualizerType = ({ AlgorithmData }) => {
  const Styles = useStyles()

  return (
    <React.Fragment>
      <div className={Styles.ArticleTitle}>
        <Typography gutterBottom variant="h3">
          <Box fontWeight={200}>{AlgorithmData.name}</Box>
        </Typography>
      </div>

      <div className={Styles.ArticleBody}>
        <Suspense fallback={<Loading />}>
          <AlgorithmData.Component />
          <FAB />
        </Suspense>
      </div>
    </React.Fragment>
  )
}

export default AlgorithmVisualizer
