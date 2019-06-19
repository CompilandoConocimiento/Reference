import React, { FunctionComponent } from "react"

import { Grid, Typography, Box, Link } from "@material-ui/core"
import { useMainStyles } from "./App/Styles"

/**
 * Just a footer :v
 */
const Footer: FunctionComponent = () => {
  const mainStyles = useMainStyles()
  return (
    <footer className={mainStyles.Footer}>
      <div className={mainStyles.FooterMain}>
        <Grid container spacing={3}>
          <Grid item xs={12} sm={8}>
            <Typography variant="subtitle1" gutterBottom>
              What is this?
            </Typography>

            <Typography variant="body2">
              The refence is a webapp/book that recopilate all the algorithms that we have
              implemented for competitive programming.
            </Typography>
          </Grid>
          <Grid item xs={12} sm={4}>
            <Typography variant="subtitle1" gutterBottom>
              Links:
            </Typography>
            <Typography variant="body2">
              <ul className={mainStyles.FooterUL}>
                <li>
                  <Typography>
                    <Box display="inline" fontWeight={600}>
                      Author:{" "}
                      <Link
                        className={mainStyles.Links}
                        href={"https://SoyOscarRH.github.io"}
                        target="_blank"
                        rel="noopener noreferrer"
                      >
                        SoyOscarRH
                      </Link>
                    </Box>
                  </Typography>
                </li>
                <li>
                  <Typography>
                    <Box display="inline" fontWeight={600}>
                      Source code:{" "}
                      <Link
                        className={mainStyles.Links}
                        href={"https://github.com/CompilandoConocimiento/Reference"}
                        target="_blank"
                        rel="noopener noreferrer"
                      >
                        Github
                      </Link>
                    </Box>
                  </Typography>
                </li>
              </ul>
            </Typography>
          </Grid>
        </Grid>
      </div>

      <div className={mainStyles.FooterEnd}>
        <Box fontWeight={800}>
          Made by CompilandoConocimiento.
        </Box>
        Making the world a happier place
      </div>
    </footer>
  )
}
export default Footer
