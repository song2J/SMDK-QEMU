import asyncio
from qemu.qmp import QMPClient
import json
import sys

async def main():
    argv = sys.argv

    qmp = QMPClient('QEMU-CMMH')
    await qmp.connect((argv[1], argv[2]))

    command = 'cxl-get-cmmh-metadata'
    data = {'path':argv[3]}
    
    res = await qmp.execute(command, data)
    print('Flash Read  cnt:\t\t', res['flash-read-cnt'])
    print('Flash Write cnt:\t\t', res['flash-write-cnt'])
    print('Flash Erase cnt:\t\t', res['flash-erase-cnt'])
    print('Write Amplification Factor(WAF):', res['write-amplification-factor'])
    print('Hit-Miss Ratio:\t\t\t', res['hit-miss-ratio'])
    print()
    print('tot read lat:\t\t', res['tot-read-lat'])
    print('tot write lat:\t\t', res['tot-write-lat'])
    await qmp.disconnect()

asyncio.run(main())
