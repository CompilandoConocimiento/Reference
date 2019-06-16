import { makeStyles, createStyles, Theme } from "@material-ui/core/styles"

const useStyles = makeStyles((theme: Theme) =>
  createStyles({
    Paper: { padding: theme.spacing(3), textAlign: "center" },
    Button: {
      padding: theme.spacing(2),
      color: "white",
      width: "100%",
      maxWidth: "22rem"
    },
  })
)

export default useStyles
