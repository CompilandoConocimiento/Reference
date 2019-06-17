import { makeStyles, createStyles, Theme } from "@material-ui/core/styles"

const useStyles = makeStyles((theme: Theme) =>
  createStyles({
    ArticleTitle: {
      textAlign: "center",
      marginBottom: "2.5rem",
      fontSize: "small"
    },
    ArticleBody: {
      [theme.breakpoints.up("sm")]: { fontSize: "inherit" },
      [theme.breakpoints.up("lg")]: { fontSize: "initial" },
    },
  })
)

export default useStyles
