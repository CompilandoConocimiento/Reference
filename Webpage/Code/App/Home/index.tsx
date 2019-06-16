import React, { useContext, FunctionComponent } from "react"

import { Grid, Typography, Button } from "@material-ui/core"
import CardToTopic from "./CardToTopic"

import { ThemeProvider } from "@material-ui/styles"
import { useTheme, responsiveFontSizes } from "@material-ui/core/styles"
import { red, indigo, cyan, green, brown } from "@material-ui/core/colors/"
import { IndexDataContext } from "../App"

const Book: FunctionComponent<{ src: string; href: string }> = ({ src, href }) => (
  <Button href={href} target="_blank" style={{ backgroundColor: "transparent" }}>
    <img style={{ maxWidth: "100%" }} src={src} />
  </Button>
)

const colors = [red[600], indigo[700], cyan[800], green[600], brown[600]].sort(
  () => Math.random() - 0.5
)

const Home: React.FunctionComponent = () => {
  const IndexData = useContext(IndexDataContext)

  let theme = useTheme()
  theme = responsiveFontSizes(theme)

  return (
    <ThemeProvider theme={theme}>
      <Grid container spacing={4}>
        {IndexData.map((Topic, index) => (
          <Grid key={index} item xs={12} sm={6}>
            <CardToTopic
              name={Topic.name}
              routeLink={Topic.link}
              backgroundColor={colors[index % colors.length]}
            />
          </Grid>
        ))}
        <Grid item xs={12}>
          <Typography gutterBottom variant="h5">
            &nbsp; &nbsp; &nbsp;
            <span style={{ fontWeight: 500 }}>Also, </span> check out:
          </Typography>
          <Grid container spacing={0}>
            <Grid item xs={12} sm={6} style={{ maxWidth: "18rem" }}>
              <Book
                href="https://compilandoconocimiento.github.io/Reference/Books/IntroToCompetitive/"
                src="Webpage/Assets/Competitive.png"
              />
            </Grid>
            <Grid item xs={12} sm={6} style={{ maxWidth: "18rem" }}>
              <Book
                href="https://compilandoconocimiento.github.io/Reference/Books/Reference/"
                src="Webpage/Assets/Reference.png"
              />
            </Grid>
          </Grid>
        </Grid>
      </Grid>
    </ThemeProvider>
  )
}

export default Home
