import { makeStyles, Theme, createStyles } from "@material-ui/core/styles"

const drawerWidth = `16rem`

const useStyles = makeStyles((theme: Theme) => {
  const Content = {
    Root: { display: "flex", minHeight: "100vh" },
    SpaceForTheHeader: theme.mixins.toolbar,
    ContentPadding: {
      paddingTop: theme.spacing(4),

      paddingLeft: theme.spacing(3),
      paddingRight: theme.spacing(3),
      
      [theme.breakpoints.up("sm")]: {
        paddingLeft: theme.spacing(6),
        paddingRight: theme.spacing(6),
      },
      [theme.breakpoints.up("md")]: {
        paddingLeft: theme.spacing(14),
        paddingRight: theme.spacing(14),
      },
      [theme.breakpoints.up("lg")]: {
        paddingLeft: theme.spacing(26),
        paddingRight: theme.spacing(26),
      },
      [theme.breakpoints.up("xl")]: {
        paddingLeft: theme.spacing(36),
        paddingRight: theme.spacing(36),
      },
    },
    Content: {
      display: "flex" as "flex",
      flexDirection: "column" as "column",
      maxWidth: "100%",
      flexGrow: 1,
      marginLeft: `-${drawerWidth}`,
      transition: theme.transitions.create("margin", {
        easing: theme.transitions.easing.sharp,
        duration: theme.transitions.duration.leavingScreen,
      }),
    },
    ContentShift: {
      [theme.breakpoints.up("sm")]: {
        marginLeft: 0,
        maxWidth: `calc(100% - ${drawerWidth})`,
        transition: theme.transitions.create("margin", {
          easing: theme.transitions.easing.easeOut,
          duration: theme.transitions.duration.enteringScreen,
        }),
      },
    },
  }

  const AppBar = {
    AppBarTitle: {
      marginLeft: theme.spacing(2),
      flexGrow: 1,
    },
    AppBarStyle: {
      transition: theme.transitions.create(["margin", "width"], {
        easing: theme.transitions.easing.sharp,
        duration: theme.transitions.duration.leavingScreen,
      }),
    },
    AppBarShift: {
      [theme.breakpoints.up("sm")]: {
        width: `calc(100% - ${drawerWidth})`,
        marginLeft: drawerWidth,
        transition: theme.transitions.create(["margin", "width"], {
          easing: theme.transitions.easing.easeOut,
          duration: theme.transitions.duration.enteringScreen,
        }),
      },
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
