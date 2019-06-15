import { makeStyles, Theme, createStyles } from "@material-ui/core/styles"

const drawerWidth = `16rem`

const useStyles = makeStyles((theme: Theme) => {
  const Content = {
    Root: { display: "flex" },
    SpaceForTheHeader: theme.mixins.toolbar,
    Content: {
      flexGrow: 1,
      padding: theme.spacing(3),
      marginLeft: `-${drawerWidth}`,
      transition: theme.transitions.create("margin", {
        easing: theme.transitions.easing.sharp,
        duration: theme.transitions.duration.leavingScreen,
      }),
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
    AppBarTitle: { flexGrow: 1 },
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
    MenuButtonDesktop: {
      marginRight: theme.spacing(2),
      [theme.breakpoints.down("xs")]: {
        display: "none",
      },
    },
    MenuButtonMobile: {
      marginRight: theme.spacing(2),
      [theme.breakpoints.up("sm")]: {
        display: "none",
      },
    },
  }

  const Drawer = {
    DrawerPaper: { width: drawerWidth },
    Drawer: { width: drawerWidth, flexShrink: 0 },
    DrawerTitle: { marginLeft: "1rem", marginTop: "1rem" },
    DrawerHeader: {
      display: "flex",
      alignItems: "center",
      padding: "0 8px",
      ...theme.mixins.toolbar,
      justifyContent: "flex-end",
    },
  }

  return createStyles({
    Hide: { display: "none" },
    ...Content,
    ...AppBar,
    ...Drawer,
  })
})

export default useStyles
