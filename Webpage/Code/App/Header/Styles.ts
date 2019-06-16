import { makeStyles, Theme, createStyles } from "@material-ui/core/styles"

const drawerWidth = `16rem`

const useStyles = makeStyles((theme: Theme) => {
  const Content = {
    Root: { display: "flex", flexGrow: 1 },
    SpaceForTheHeader: theme.mixins.toolbar,
    Content: {
      flexGrow: 1,
      paddingLeft: theme.spacing(4),
      paddingRight: theme.spacing(4),
      paddingTop: theme.spacing(6),
      marginLeft: `-${drawerWidth}`,
      transition: theme.transitions.create("margin", {
        easing: theme.transitions.easing.sharp,
        duration: theme.transitions.duration.leavingScreen,
      }),
      [theme.breakpoints.up("md")]: {
        paddingLeft: theme.spacing(10),
        paddingRight: theme.spacing(10),
      },
      [theme.breakpoints.up("lg")]: {
        paddingLeft: theme.spacing(10),
        paddingRight: theme.spacing(18),
      },
    },
    ContentShift: {
      marginLeft: 0,
      transition: theme.transitions.create("margin", {
        easing: theme.transitions.easing.easeOut,
        duration: theme.transitions.duration.enteringScreen,
      }),
    },
  }

  const AppBar = {
    AppBarTitle: {
      marginLeft: theme.spacing(2),
      flexGrow: 1,
    },
    AppBar: {
      transition: theme.transitions.create(["margin", "width"], {
        easing: theme.transitions.easing.sharp,
        duration: theme.transitions.duration.leavingScreen,
      }),
    },
    AppBarShift: {
      width: `calc(100% - ${drawerWidth})`,
      marginLeft: drawerWidth,
      transition: theme.transitions.create(["margin", "width"], {
        easing: theme.transitions.easing.easeOut,
        duration: theme.transitions.duration.enteringScreen,
      }),
    },
    MenuButtonDesktop: { [theme.breakpoints.down("xs")]: { display: "none" } },
    MenuButtonMobile: { [theme.breakpoints.up("sm")]: { display: "none" } },
  }

  const Drawer = {
    Drawer: { width: drawerWidth, flexShrink: 0 },
    DrawerPaper: { width: drawerWidth },
    DrawerTitle: { fontWeight: 600, fontSize: "1.5rem" },
    DrawerTopic: { paddingLeft: theme.spacing(2), fontWeight: 600 },
    DrawerAlgorithm: { paddingLeft: theme.spacing(4) },
  }

  return createStyles({
    Hide: { display: "none" },
    ...Content,
    ...AppBar,
    ...Drawer,
  })
})

export default useStyles
