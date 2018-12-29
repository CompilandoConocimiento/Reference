import DirectoryData from "./Directory"
export const Directory = DirectoryData

//import DynamicProgramming from './DynamicProgramming'
//import Search             from './Search'
//import Strings            from './Strings'
import NumberTheory         from './NumberTheory'

export const TopicsData: Array<TopicData> = [
    NumberTheory,
]

import {NameLink as NameLinkInterface} from "./types"
import {AlgorithmData as AlgorithmDataInterface, TopicData as TopicDataInterface} from "./types"
import {FilesData as FilesDataInterface, CodeStyles as CodeStylesInterfaces, CodeActions as CodeActionsInterfaces } from "./types"

export type NameLink = NameLinkInterface

export type AlgorithmData = AlgorithmDataInterface
export type TopicData = TopicDataInterface

export type FilesData = FilesDataInterface
export type CodeStyles = CodeStylesInterfaces
export type CodeActions = CodeActionsInterfaces
