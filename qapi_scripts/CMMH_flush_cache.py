import asyncio
from qemu.qmp import QMPClient
import json
import sys

async def main():
    argv = sys.argv

    qmp = QMPClient('QEMU-CMMH')
    await qmp.connect((argv[1], argv[2]))

    command = 'cxl-cmmh-flush-cache'
    data = {'path':argv[3]}
    
    res = await qmp.execute(command, data)
    await qmp.disconnect()

asyncio.run(main())
