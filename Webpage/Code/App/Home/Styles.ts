import { makeStyles, createStyles } from "@material-ui/core/styles"

const useStyles = makeStyles(() =>
  createStyles({
    Card: {
      cursor: "pointer",
      borderRadius: "1.2rem",
      padding: "1.2rem"
    },
    Text: {
      color: "white"
    },
    Divider: {
      borderTop: "4px solid rgba(255, 255, 255, 0.3)",
      marginBottom: "1rem",
    }
  })
)

export default useStyles
