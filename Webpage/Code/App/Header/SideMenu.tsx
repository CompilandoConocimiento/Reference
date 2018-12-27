import React from "react"
import Topics from '../../Data'
import { Link } from 'react-router-dom'

interface SideMenuProps {
	CloseSideMenu: () => void
}
const SideMenu: React.FunctionComponent<SideMenuProps> = props => {

	const TopicsLink: Array<JSX.Element> = Topics.map( (Topic, indexTopic) =>
      <React.Fragment key={`Render ${indexTopic}`}>

        <li key={`Divider ${indexTopic}`}>
          <div className="divider" />
        </li>

        <li key={Topic.link}>
          <Link className="waves-effect" onClick={props.CloseSideMenu} to={`/Topic/${Topic.link}/`}>
            <span style={{fontSize: "1.1rem"}}>{Topic.name}</span>
          </Link>
        </li>

        {
          Topic.subTopics.map( (SubTopic, indexSubTopic) =>
            <li key={`${Topic.link} ${indexTopic} ${indexSubTopic}`}>
              <Link className="waves-effect" onClick={props.CloseSideMenu} to={`/Topic/${Topic.link}/${SubTopic.link}`}>
                &nbsp;{SubTopic.name}
              </Link>
            </li>
          )
        }

      </React.Fragment>
	)
	
	return (
		<ul id="SideBarID" className="sidenav">

          <li>
            <br />
            <h5 className="blue-grey-text text-darken-3">
              <span style={{fontWeight: 500, fontSize: "2.1rem"}}>
                &nbsp;&nbsp;&nbsp;&nbsp; <b>Topics</b>
              </span>
            </h5>
          </li>

          <br />

          {TopicsLink}

          <br /><br />
          <br /><br />

        </ul>
	)
}

export default SideMenu