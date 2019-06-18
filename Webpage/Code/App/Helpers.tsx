import React, { FunctionComponent } from "react"

import { Paper, Box, Typography, LinearProgress } from "@material-ui/core"
import useCardStyle from "./AlgorithmsPicker/Styles"

/**
 * Just to to top smoothly
 */
export const toTop = () => window.scroll({ top: 0, behavior: "smooth" })

/**
 * A component to call when loading something
 */
export const Loading: FunctionComponent = () => <LinearProgress style={{height: "16px", borderRadius: "8px"}} />

/**
 * A component to call when something went wrong
 */
export const ErrorMessage: FunctionComponent = () => {
  const Styles = useCardStyle()

  return (
    <Paper className={Styles.Paper}>
      <Typography gutterBottom variant="h4">
        <Box fontWeight={500}>Error: Something did not go right. Sorry :(</Box>
      </Typography>
      <br />
    </Paper>
  )
}
